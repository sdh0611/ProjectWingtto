#include "../pch.h"
#include "../Include/SceneManager.h"
#include "../Include/Scene.h"
#include "../Include/GameScene.h"
//Scene���� Change ��ȣ�� ������ ��ü



SceneManager::SceneManager()
	:m_pScene(nullptr), m_pNextScene(nullptr){
	//MessageBox(NULL, TEXT("SceneManager �����ڽ���"), TEXT("Info"), MB_ICONINFORMATION);


}

SceneManager::~SceneManager() {

	//MessageBox(NULL, TEXT("SceneManager �Ҹ��ڽ���"), TEXT("Info"), MB_ICONINFORMATION);
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
	//���� SceneType �ʱ�ȭ
	m_SceneType = type;
	CreateScene(type);


	return true;
}

//Scene ����
//void SceneManager::Run() {
//
//	mScene->Update();
//	mScene->Render(HDC hDC);
//
//	//Scene�� ��ü�ؾ� �ϴ��� �˻��Ѵ�.
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

//���� Scene �ʱ�ȭ
//�������� Scene�� Init�κ�
void SceneManager::CreateScene(Types::SceneType type) {
		
	if (m_pScene != nullptr)
		delete m_pScene;

	//TITLE, SELECT�� ���� �����������Ƿ� �ϴ� �ȳ���(18.04.14)
	switch (type) {
	case Types::ST_GAME:
		m_pScene = new GameScene;
		m_pScene->Init();
		break;

	}

	//m_SceneType = type;


}

//NextScene �غ��ϴ� �Լ�
void SceneManager::CreateNextScene(Types::SceneType type) {
	
	if (m_pScene != nullptr)
		delete m_pNextScene;

	//TITLE, SELECT�� ���� �����������Ƿ� �ϴ� �ȳ���(18.04.14)
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
