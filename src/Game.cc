#include "CommonHeaders.hh"
#include "Player.hh"
#include "TileGroup.hh"
#include "Enemy.hh"

sf::CircleShape* circle{new sf::CircleShape()};

TextObject* textObj1{new TextObject(ASSETS_FONT_PSYCHOPATHY, 50, sf::Color::White, sf::Text::Bold)};
 Audio* audioObjt1{new Audio(ASSETS_AUDIO_LABYRINTH, 60.f)};

sf::Clock* gameClock{new sf::Clock()};
float deltaTime{};
Player* player1{};
GameObject* chest1{};
GameObject* light1{};
GameObject* pilar1{};
GameObject* pilar2{};
GameObject* pilar3{};
GameObject* pilar4{};
GameObject* pilar5{};
GameObject* pilar6{};
GameObject* pilar7{};
GameObject* pilar8{};
GameObject* pilar9{};
GameObject* pilar10{};
GameObject* pilar11{};
GameObject* pilar12{};
GameObject* pilar13{};
GameObject* pilar14{};
GameObject* pilar15{};
GameObject* pilar16{};
GameObject* pilar17{};
GameObject* pilar18{};
GameObject* pilar19{};
GameObject* pilar20{};
GameObject* pilar21{};
GameObject* pilar22{};
GameObject* pilar23{};
GameObject* pilar24{};
GameObject* pilar25{};
GameObject* pilar26{};
GameObject* pilar27{};
GameObject* pilar28{};
GameObject* pilar29{};
GameObject* pilar30{};

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
  player1 = new Player(ASSETS_SPRITES, 4.f, 16, 16, 0, 5, 100, 100, 200.f, b2BodyType::b2_dynamicBody, world, window);
  player1->SetTagName("Player");
  chest1 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 6, 1, 300, 500, b2BodyType::b2_staticBody, world, window);
  chest1->SetTagName("chest");
  /*light1 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 6, 3, 500, 500, b2BodyType::b2_staticBody, world, window);
  light1->SetTagName("light");
  //wall1 = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 100, 300, b2BodyType::b2_staticBody, world, window);
  wall1->SetTagName("wall");*/
  enemy1 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 3, 150, 300, 500.f, b2BodyType::b2_dynamicBody, world, window, 0.9f, sf::Vector2f(1,0));
  enemy1->SetTagName("enemy");
  enemy2 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 3, 200, 200, 400.f, b2BodyType::b2_dynamicBody, world, window, 1.0f, sf::Vector2f(1,0));
  enemy2->SetTagName("enemy");
  enemy3 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 3, 250, 400, 500.f, b2BodyType::b2_dynamicBody, world, window, 0.9f, sf::Vector2f(1,0));
  enemy3->SetTagName("enemy");
  enemy4 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 3, 100, 700, 400.f, b2BodyType::b2_dynamicBody, world, window, 1.0f, sf::Vector2f(1,0));
  enemy4->SetTagName("enemy");
  enemy5 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 3, 150, 600, 500.f, b2BodyType::b2_dynamicBody, world, window, 0.9f, sf::Vector2f(1,0));
  enemy5->SetTagName("enemy");

  pilar1 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 50, 50, b2BodyType::b2_staticBody, world, window);
  pilar1->SetTagName("pilar");
  pilar2 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 150, 50, b2BodyType::b2_staticBody, world, window);
  pilar2->SetTagName("pilar");
  pilar3 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 250, 50, b2BodyType::b2_staticBody, world, window);
  pilar3->SetTagName("pilar");
  pilar4 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 350, 50, b2BodyType::b2_staticBody, world, window);
  pilar4->SetTagName("pilar");
  pilar5 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 450, 50, b2BodyType::b2_staticBody, world, window);
  pilar5->SetTagName("pilar");
  pilar6 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 550, 50, b2BodyType::b2_staticBody, world, window);
  pilar6->SetTagName("pilar");
  pilar7 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 650, 50, b2BodyType::b2_staticBody, world, window);
  pilar7->SetTagName("pilar");
  pilar8 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 750, 50, b2BodyType::b2_staticBody, world, window);
  pilar8->SetTagName("pilar");
  pilar9 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 750, 200, b2BodyType::b2_staticBody, world, window);
  pilar9->SetTagName("pilar");
  pilar10 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 750, 300, b2BodyType::b2_staticBody, world, window);
  pilar10->SetTagName("pilar");
  pilar11 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 750, 400, b2BodyType::b2_staticBody, world, window);
  pilar11->SetTagName("pilar");
  pilar12 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 750, 500, b2BodyType::b2_staticBody, world, window);
  pilar12->SetTagName("pilar");
  pilar13 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 750, 600, b2BodyType::b2_staticBody, world, window);
  pilar13->SetTagName("pilar");
  pilar14 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 750, 700, b2BodyType::b2_staticBody, world, window);
  pilar14->SetTagName("pilar");
  pilar15 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 750, 800, b2BodyType::b2_staticBody, world, window);
  pilar15->SetTagName("pilar");
  pilar16 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 650, 800, b2BodyType::b2_staticBody, world, window);
  pilar16->SetTagName("pilar");
  pilar17 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 550, 800, b2BodyType::b2_staticBody, world, window);
  pilar17->SetTagName("pilar");
  pilar18 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 450, 800, b2BodyType::b2_staticBody, world, window);
  pilar18->SetTagName("pilar");
  pilar19 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 350, 800, b2BodyType::b2_staticBody, world, window);
  pilar19->SetTagName("pilar");
  pilar20 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 250, 800, b2BodyType::b2_staticBody, world, window);
  pilar20->SetTagName("pilar");
  pilar21 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 150, 800, b2BodyType::b2_staticBody, world, window);
  pilar21->SetTagName("pilar");
  pilar22 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 50, 800, b2BodyType::b2_staticBody, world, window);
  pilar22->SetTagName("pilar");
  pilar22 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 50, 800, b2BodyType::b2_staticBody, world, window);
  pilar22->SetTagName("pilar");
  pilar23 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 5, 700, b2BodyType::b2_staticBody, world, window);
  pilar23->SetTagName("pilar");
  pilar24 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 5, 600, b2BodyType::b2_staticBody, world, window);
  pilar24->SetTagName("pilar");
  pilar25 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 5, 500, b2BodyType::b2_staticBody, world, window);
  pilar25->SetTagName("pilar");
  pilar26 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 5, 400, b2BodyType::b2_staticBody, world, window);
  pilar26->SetTagName("pilar");
  pilar27 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 5, 300, b2BodyType::b2_staticBody, world, window);
  pilar27->SetTagName("pilar");
  pilar28 = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 5, 200, b2BodyType::b2_staticBody, world, window);
  pilar28->SetTagName("pilar");
  

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
  
  AddGameObject(chest1);
  AddGameObject(enemy1);
  AddGameObject(enemy2);
  AddGameObject(enemy3);
  AddGameObject(enemy4);
  AddGameObject(enemy5);
  AddGameObject(pilar1);
  AddGameObject(pilar2);
  AddGameObject(pilar3);
  AddGameObject(pilar4);
  AddGameObject(pilar5);
  AddGameObject(pilar6);
  AddGameObject(pilar7);
  AddGameObject(pilar8);
  AddGameObject(pilar9);
  AddGameObject(pilar10);
  AddGameObject(pilar11);
  AddGameObject(pilar12);
  AddGameObject(pilar13);
  AddGameObject(pilar14);
  AddGameObject(pilar15);
  AddGameObject(pilar16);
  AddGameObject(pilar17);
  AddGameObject(pilar18);
  AddGameObject(pilar19);
  AddGameObject(pilar20);
  AddGameObject(pilar21);
  AddGameObject(pilar22);
  AddGameObject(pilar28);
  AddGameObject(pilar27);
  AddGameObject(pilar26);
  AddGameObject(pilar25);
  AddGameObject(pilar24);
  AddGameObject(pilar23);
  AddGameObject(player1);

  textObj1->SetTextStr("Dungeon of the Death");
  //audioObjt1->play();
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