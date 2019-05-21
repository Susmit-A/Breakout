#include <string>
#include "game_object.hpp"

void text();
void display();
void onTimerTick(int flag);
void init();
void loadDefaultLayout();
void reset();
void keyPressed(unsigned char key, int x, int y);
void specialKeyPressed(int key, int x, int y);
void ballWallCollider(GameObject *obj1, GameObject *obj2, std::string name, unsigned char code);
void ballBlockCollider(GameObject *obj1, GameObject *obj2, std::string name, unsigned char code);
void ballPaddleCollider(GameObject *obj1, GameObject *obj2, std::string name, unsigned char code);
void loadLayoutFromFile(const char* path);
