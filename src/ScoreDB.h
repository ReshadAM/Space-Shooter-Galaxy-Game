#ifndef SCOREDB_H
#define SCOREDB_H

#include <vector>
#include "sqlite3.h"
#include "ScoreField.h"

/**
 * ScoreDB class.
 *
 * This class creates a Sqlite3 data base and provides functions to add player scores and retrieve them from the db.
 * This class
 *
 * \author Jake Bunting (Jbuntin4)
 */
class ScoreDB {
private:
    const char* const SQL_DB_PATH = "score_db";         /**< path to db file */
    const std::string TABLE_NAME = "highscore_test2";    /**< name of db table */
    sqlite3 *_dbHandle;                                 /**< db handle */

public:
    /**
     * ScoreDB - creates a DB for the high scores.
     */
    ScoreDB();

    /**
     * ~ScoreDB - Close connection to the score DB.
     */
    virtual ~ScoreDB();

    /**
     * AddScoreToDB - Add the players name and score to the score DB.
     * \param playerName player name.
     * \param score player score.
     */
    void AddScoreToDB(std::string playerName, std::string score);

    /**
     * GetTopScores - Retrieves top ten scores in the DB.
     * \return vector of ScoreField objects
     */
    std::vector<ScoreField> GetTopScores();
};

#endif