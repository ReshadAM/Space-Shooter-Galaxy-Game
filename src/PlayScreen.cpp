#include "PlayScreen.h"

PlayScreen::PlayScreen() {
    Engine::getInstance()->getSoundEffect()->addSoundEffect("res/blaster.wav");
    Engine::getInstance()->getSoundEffect()->addSoundEffect("res/laser.wav");

    int playerX = (Engine::InternalWidth / 2) - (player.getBounds().w / 2);
    int playerY = (Engine::InternalHeight / 2) - (player.getBounds().h / 2);
    player.setPosition(playerX, playerY);

    // Test.
    enemies.push_back(new EnemyShip(500, 100));
    // enemies.push_back(new EnemyShip(500, 300));
}

PlayScreen::~PlayScreen() {

}

void PlayScreen::update() {
    // Update player and enemies.
    player.update(&bullets);
    SDL_Rect playerBounds = player.getBounds();

    for (int i = 0; i < enemies.size(); i++)
        enemies[i]->update(player.getCenterX(), player.getCenterY(), &bullets, player.getLocalX(), player.getLocalY());

    // Bullet logic.
    for (int i = bullets.size() - 1; i >= 0; i--) {
        bullets[i]->update();
        SDL_Rect bulletBounds = bullets[i]->getBounds();

        // Check if the player got hit. 
        if (bullets[i]->getSource() == BulletSource::enemy) {
            if (SDL_HasIntersection(&playerBounds, &bulletBounds)) {
                player.decrementHealth();
                bullets[i]->markForDeletion();
            }
        }

        // Check if an enemy got hit.
        if (bullets[i]->getSource() == BulletSource::player) {
            for (int i = 0; i < enemies.size(); i++) {
                SDL_Rect enemyBounds = enemies[i]->getBounds();
                if (SDL_HasIntersection(&enemyBounds, &bulletBounds)) {
                    enemies[i]->decrementHealth();
                    bullets[i]->markForDeletion();
                }
            }
        }
    }

    // Delete expired bullets.
    for (int i = bullets.size() - 1; i >= 0; i--) {
        if (bullets[i]->isMarkedForDeletion()) {
            Bullet* expiredBullet = bullets[i];
            bullets.erase(bullets.begin() + i);
            delete expiredBullet;
        }
    }

    // Delete dead enemies.
    for (int i = enemies.size() - 1; i >= 0; i--) {
        if (enemies[i]->getHealth() <= 0) {
            EnemyShip* deadEnemy = enemies[i];
            enemies.erase(enemies.begin() + i);
            delete deadEnemy;
        }
    }

    // Update health bar and change scenes if the player died.
    _healthBar.update(player.getHealth());
    if (player.getHealth() <= 0)
        Engine::getInstance()->setScreen(new StartScreen());

    // Temporary until we have a wave system.
    if (enemies.size() == 0)
        Engine::getInstance()->setScreen(new StartScreen());
}

void PlayScreen::draw() {
    // Draw enemies, bullets, players.
    for (int i = bullets.size() - 1; i >= 0; i--)
        bullets[i]->draw();
    for (int i = 0; i < enemies.size(); i++)
        enemies[i]->draw();
    player.draw();
    _healthBar.draw();
}
