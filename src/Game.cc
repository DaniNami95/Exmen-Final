#include "CommonHeaders.hh"
#include "Player.hh"
#include "TileGroup.hh"
#include "Enemy.hh"

sf::CircleShape* circle{new sf::CircleShape()};

TextObject* textObj1{new TextObject(ASSETS_FONT_PSYCHOPATHY, 50, sf::Color::White, sf::Text::Bold)};

sf::Clock* gameClock{new sf::Clock()};
float deltaTime{};
Player* player1{};
GameObject* chest1{};
GameObject* light1{};
GameObject* pillar{};
GameObject* wall1{};
Enemy* enemy1{};
Enemy* enemy2{};
Enemy* enemy3{};
Enemy* enemy4{};
Enemy* enemy5{};

TileGroup* tileGroup{};
Tile* tile1{};

uint32 flags{};
    //flags += b2Draw::e_aabbBit;
    //flags += b2Draw::e_shapeBit;
    //flags += b2Draw::e_centerOfMassBit;
    //flags += b2Draw::e_pairBit;
    //flags += b2Draw::e_jointBit;

Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
  event = new sf::Event();
  gravity = new b2Vec2(0.f, 0.f);
  world = new b2World(*gravity);
  drawPhysics = new DrawPhysics(window);
  gameObjects = new std::vector<GameObject*>();
  gameObjectsDeleteList = new std::vector<GameObject*>();
  player1 = new Player(ASSETS_SPRITES, 4.f, 16, 16, 0, 5, 500, 100, 200.f, b2BodyType::b2_dynamicBody, world, window);
  player1->SetTagName("Player");
  chest1 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 6, 1, 300, 500, b2BodyType::b2_staticBody, world, window);
  chest1->SetTagName("chest");
  /*light1 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 6, 3, 500, 500, b2BodyType::b2_staticBody, world, window);
  light1->SetTagName("light");
  //wall1 = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 100, 300, b2BodyType::b2_staticBody, world, window);
  wall1->SetTagName("wall");*/
  enemy1 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 3, 275, 250, 300.f, b2BodyType::b2_dynamicBody, world, window, 1.4f, sf::Vector2f(1,0));
  enemy1->SetTagName("enemy");
  enemy2 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 3, 200, 600, 300.f, b2BodyType::b2_dynamicBody, world, window, 1.4f, sf::Vector2f(1,0));
  enemy2->SetTagName("enemy");
  enemy3 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 3, 400, 200, 300.f, b2BodyType::b2_dynamicBody, world, window, 1.4f, sf::Vector2f(1,0));
  enemy3->SetTagName("enemy");
  enemy4 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 3, 100, 400, 300.f, b2BodyType::b2_dynamicBody, world, window, 1.4f, sf::Vector2f(1,0));
  enemy4->SetTagName("enemy");
  enemy5 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 3, 50, 700, 300.f, b2BodyType::b2_dynamicBody, world, window, 1.4f, sf::Vector2f(1,0));
  enemy5->SetTagName("enemy");
  tileGroup = new TileGroup(window, 12, 12, ASSETS_MAPS, 4.f, 16, 16, ASSETS_TILES);
  contactEventManager = new ContactEventManager(gameObjects, gameObjectsDeleteList);
}

Game::~Game()
{
}

//Starting things
void Game::Start()
{
  flags += b2Draw::e_shapeBit;
  world->SetDebugDraw(drawPhysics);
  drawPhysics->SetFlags(flags);
  world->SetContactListener(contactEventManager);
  AddGameObject(player1);
  AddGameObject(chest1);
  AddGameObject(enemy1);
  AddGameObject(enemy2);
  AddGameObject(enemy3);
  AddGameObject(enemy4);
  AddGameObject(enemy5);
  textObj1->SetTextStr("Dungeon of the Death");
}

void Game::Initialize()
{
  Start();
  MainLoop();
}

void Game::UpdatePhysics()
{
  world->ClearForces();
  world->Step(deltaTime, 8, 8);
}

//Logic, animations, etc
void Game::Update()
{
  deltaTime = gameClock->getElapsedTime().asSeconds();
  gameClock->restart();

  for(auto &gameObject : *gameObjects)
  {
    gameObject->Update(deltaTime);
  }
}

void Game::MainLoop()
{
  while (window->isOpen())
  {
    while(window->pollEvent(*event))
    {
      if(event->type == sf::Event::Closed)
      {
        window->close();
      }
    }
    UpdatePhysics();
    Input();
    Update();
    Render();
  }
  Destroy();
}

void Game::Render()
{
  for(auto& gameobject: *gameObjectsDeleteList)
  {
      gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), gameobject), gameObjects->end());
      delete gameobject;
  }
  gameObjectsDeleteList->clear();

  window->clear(sf::Color::Black);
  Draw();
  window->display();
}

//Drawing sprites or geometry.
void Game::Draw()
{
  tileGroup->Draw();

  for(auto &gameObject : *gameObjects)
  {
    gameObject->Draw();
  }

  window->draw(*textObj1->GetText());
}

//Keyboard, joysticks, etc.
void Game::Input()
{
}

void Game::Destroy()
{
  delete window;
  delete event;
}

void Game::AddGameObject(GameObject* gameObject)
{
  gameObjects->push_back(gameObject);
}