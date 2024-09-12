#include <string>

/**
 * ScoreField class.
 *
 * This class defines an object that stores the player name and their score.
 *
 * \author Jake Bunting (jbuntin4)
 */
class ScoreField {
private:
    std::string _playerName;    /**< name of the player */
    std::string _score;         /**< players score */
public:
    /**
     * ScoreField - Create a ScoreField object to hold player name and their score.
     * \param playerName player's name.
     * \param score player's score.
     */
    ScoreField(std::string playerName, std::string score);

    /**
     * ~ScoreField - Destructor for score field object.
     */
    ~ScoreField();

    /**
     * getPlayerName - Getter method to get player name.
     * \return string player's name.
     */
    std::string getPlayerName() const;

    /**
     * getPlayerName - Getter method to get player score.
     * \return string player's score.
     */
    std::string getScore() const;
};