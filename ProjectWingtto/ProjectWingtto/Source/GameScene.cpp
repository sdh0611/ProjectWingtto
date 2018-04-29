#include "../pch.h"
#include "../Include/GameScene.h"
#include "../Include/Object.h"
#include "../Include/CPlayer.h"
#include "../Include/CEnemy.h"
#include "../Include/Layer.h"
#include "../Include/ComponentBase.h"
#include "../Include/Collider.h"
#include "../Include/ColliderBox.h"
#include "../Include/CollisionDetector.h"




GameScene::GameScene()
	:Scene(), m_pPlayer(nullptr), m_pCollision(nullptr)
{


}


GameScene::~GameScene()
{
	
	SAFE_DELETE(m_pPlayer)

}


//bool GameScene::Init(const HDC& hDC) {
//
//	//플레이어 객체 초기화
//	SAFE_DELETE(m_pPlayer)
//	
//	m_pPlayer = new CPlayer;
//	m_pPlayer->Init(hDC);
//	//초기 GameObject들 초기화하는 부분.
//
//
//
//	return true;
//}

bool GameScene::Init() {


	//플레이어 객체 초기화
	//SAFE_DELETE(m_pPlayer)

	m_pPlayer = new CPlayer;
	if (!m_pPlayer->Init())
		return false;

	if (!m_pCollision->Init())
		return false;

	CreateLayer("Enemy", 0);
	FindLayer("Enemy")->AddObject(new CEnemy);
	FindLayer("Enemy")->AddObject(new CEnemy(Types::POINT(500, 250)));


	Object* test = new CPlayer;
	//초기 Layer들 초기화하는 부분.
	for (m_lIt = m_lLayers.begin(); m_lIt != m_lLayers.end(); ++m_lIt) {
		if (!(*m_lIt)->Init())
			return false;
	}

	return true;
}


void GameScene::Update(float deltaTime) {
	
	m_pPlayer->Update(deltaTime);
	Scene::Update(deltaTime);			//Layer Update()
	//DetectCollsion();
	//m_pCollision->Update();

}


void GameScene::Render(float deltaTime, const HDC& hDC) {
	
	m_pPlayer->Render(deltaTime, hDC);
	Scene::Render(deltaTime, hDC);

}




//게임 Object를 추가하는 부분.
bool GameScene::AddObject(const std::string& layerTag, Types::ObjectType type)
{
	Layer* layer = FindLayer(layerTag);
	

	switch (type) {
	case Types::OT_ENUMY:
		//layer->AddObject(new CEnemy);
		break;

	}

	return true;

}

bool GameScene::DetectCollsion()
{
	ComponentBase* pComponent;
	//ColliderBox* box = static_cast<ColliderBox*>(pComponent);



	if (pComponent->GetName().compare("ColliderRect")) {
		

	}

	for (m_lIt = m_lLayers.begin(); m_lIt != m_lLayers.end(); ++m_lIt) {


	}


	return false;
}
