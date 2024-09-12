//
// Created by jbunt on 26-Oct.-22.
//
#include "ScoreDB.h"
#include <iostream>

using namespace std;

ScoreDB::ScoreDB() {
    // set up connection to the sql db
    int rc = sqlite3_open(SQL_DB_PATH, &_dbHandle);
    if (rc != SQLITE_OK) {
        cout << rc << endl;
        cout << "Issue opening sql db in ScoreDB(). Terminating program!" << endl;
        exit(1);
    }

    // create a table if one does not already exist for the specified app name
    string sql = "create table if not exists " + TABLE_NAME + " (playerName varchar(255), score int);";
    rc = sqlite3_exec(_dbHandle, sql.c_str() , NULL, NULL, NULL);

    if (rc != SQLITE_OK) {
        cout << rc << endl;
        cout << "Issue executing create table in ScoreDB(). Terminating program!" << endl;
        exit(1);
    }
}

ScoreDB::~ScoreDB() {
    int rc = sqlite3_close_v2(_dbHandle);
    if (rc != SQLITE_OK) {
        cout << "Issue sql sql db in ~ScoreDB(). Terminating program!" << endl;
        exit(1);
    }
}

void ScoreDB::AddScoreToDB(string playerName, string score) {
    // write player name and score to the db
    string sql = "insert into " + TABLE_NAME + " values (\"" + playerName  +"\", \"" + score + "\");";
    int rc = sqlite3_exec(_dbHandle, sql.c_str(), NULL, NULL, NULL);

    if (rc != SQLITE_OK) {
        cout << "Issue executing insert into db from write(). Terminating program!" << endl;
        exit(1);
    }
}

vector<ScoreField> ScoreDB::GetTopScores() {
    vector<ScoreField> scores;
    sqlite3_stmt *stmt;
    string playerName;
    string score;

    // prepare sql statement
    string sql = "select * from " + TABLE_NAME + " order by score desc";
    int rc_prep = sqlite3_prepare_v2(_dbHandle, sql.c_str(), -1, &stmt, 0);

    // exit if prepare return code is not ok
    if (rc_prep != SQLITE_OK) {
        cout << "Issue creating prepared statement in GetAllScores(). Terminating program!" << endl;
        cout << sqlite3_errmsg(_dbHandle) << endl;
        exit(1);
    }

    // loop through the table rows
    int rc_step;
    int count = 0;
    while (count < 10) {
        rc_step = sqlite3_step(stmt);
        if (rc_step == SQLITE_DONE) {
            break;
        }
        count++;
        if (rc_step == SQLITE_ERROR ) {
            cout << rc_step << endl;
            cout << "Issue stepping through prepared statement in GetAllScores(). Terminating program!" << endl;
            exit(1);
        }

        // cast values to string
        playerName = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        score = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));

        ScoreField *newField = new ScoreField(playerName, score);
        scores.push_back(*newField);
    }

    int rc_f = sqlite3_finalize(stmt);
    if (rc_f != SQLITE_OK) {
        cout << "Issue deleting prepared statement in GetAllScores(). Terminating program!" << endl;
        exit(1);
    }

    return scores;
}
