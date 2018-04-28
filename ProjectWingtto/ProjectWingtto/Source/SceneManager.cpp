#include "../pch.h"
#include "../Include/SceneManager.h"
#include "../Include/Scene.h"
#include "../Include/GameScene.h"
//Scene에서 Change 신호를 보내면 교체



SceneManager::SceneManager()
	:m_pScene(nullptr), m_pNextScene(nullptr){
	//MessageBox(NULL, TEXT("SceneManager 생성자실행"), TEXT("Info"), MB_ICONINFORMATION);


}

SceneManager::~SceneManager() {

	//MessageBox(NULL, TEXT("SceneManager 소멸자실행"), TEXT("Info"), MB_ICONINFORMATION);
	SAFE_DELETE(m_pScene)
	SAFE_DELETE(m_pNextScene)

}

bool SceneManager::Init(Types::SceneType type, HDC& hDC) {
	//MessageBox(NULL, TEXT("SceneManager Init"), TEXT("Info"), MB_ICONINFORMATION);

	if (m_pScene != nullptr) {
		delete m_pScene;
		m_pScene = nullptr;
	}

	if (m_pNextScene != nullptr){
		delete m_pNextScene;
		m_pNextScene = nullptr;
	}

	m_hDC = hDC;
	//현재 SceneType 초기화
	m_SceneType = type;
	CreateScene(type);


	return true;
}

//Scene 실행
//void SceneManager::Run() {
//
//	mScene->Update();
//	mScene->Render(HDC hDC);
//
//	//Scene을 교체해야 하는지 검사한다.
//	mIsChangeScene = mScene->IsChangeScene();
//	if (mIsChangeScene)
//		ChangeScene();
//
//}

void SceneManager::Render(float deltaTime, const HDC& hDC) {

	m_pScene->Render(deltaTime, hDC);

}


void SceneManager::Update(float deltaTime) {

	m_pScene->Update(deltaTime);

}


void SceneManager::CheckSChangeScene() {

	m_bIsChangeScene = m_pScene->IsChangeScene();
	if (m_bIsChangeScene) {
		ChangeScene();
	}

}

//현재 Scene 초기화
//실질적인 Scene의 Init부분
void SceneManager::CreateScene(Types::SceneType type) {
		
	if (m_pScene != nullptr)
		delete m_pScene;

	//TITLE, SELECT는 아직 구현안했으므로 일단 안넣음(18.04.14)
	switch (type) {
	case Types::ST_GAME:
		m_pScene = new GameScene;
		m_pScene->Init();
		break;

	}

	//m_SceneType = type;


}

//NextScene 준비하는 함수
void SceneManager::CreateNextScene(Types::SceneType type) {
	
	if (m_pScene != nullptr)
		delete m_pNextScene;

	//TITLE, SELECT는 아직 구현안했으므로 일단 안넣음(18.04.14)
	switch (type) {
	case Types::ST_GAME:
		m_pNextScene = new GameScene();
		m_pNextScene->Init();
		break;

	}


}


bool SceneManager::ChangeScene() {

	Scene* temp = m_pScene;

	if (m_pNextScene == nullptr)
		return false;

	m_pScene = m_pNextScene;
	m_pNextScene = nullptr;

	delete temp;

	return true;
}
