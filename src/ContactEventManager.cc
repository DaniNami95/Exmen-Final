#include "ContactEventManager.hh"
#include "GameObject.hh"
#include<iostream>
//#include "TextObject.hh"
//#include "Constants.hh"

//TextObject* textObj1{new TextObject(ASSETS_FONT_PSYCHOPATHY, 50, sf::Color::White, sf::Text::Bold)};

ContactEventManager::ContactEventManager(std::vector<GameObject*>*& gameObjects, std::vector<GameObject*>*& gameObjectsDeleteList)
{
  this->gameObjects = gameObjects;
  this->gameObjectsDeleteList = gameObjectsDeleteList;
}

ContactEventManager::~ContactEventManager()
{
  
}

void ContactEventManager::BeginContact(b2Contact* contact)
{
  GameObject* actorA{(GameObject*)contact->GetFixtureA()->GetBody()->GetUserData().pointer};
  GameObject* actorB{(GameObject*)contact->GetFixtureB()->GetBody()->GetUserData().pointer};

  if(actorA && actorB)
  {
    std::cout << "Collision: " << actorA->GetTagName() << ", " << actorB->GetTagName() << std::endl;
    if(actorB->GetTagName().compare("chest")==0)
    {
      gameObjectsDeleteList->push_back(actorB);
      //textObj1->SetTextStr("Ganaste");
    }
  }
  
  if(actorB->GetTagName().compare("enemy")==0)
  {
    exit(-1);
  }
}

void ContactEventManager::EndContact(b2Contact* contact)
{

}