#include "../Include/Scene.h"
#include "../Include/Layer.h"

Scene::Scene() : m_bChangeScene(false) { 

	CreateLayer("Default");
	
}


Scene::~Scene() {

	if(!m_lLayers.empty())
		for (m_lIt = m_lLayers.begin(); m_lIt != m_lLayers.end(); ++m_lIt) {
			delete *m_lIt;
		}

	m_lLayers.clear();
	
}


bool Scene::Init() {

	for (m_lIt = m_lLayers.begin(); m_lIt != m_lLayers.end(); ++m_lIt) {
		if (!(*m_lIt)->Init())
			return false;
	}

	return true;
}


void Scene::Update(float deltaTime) {

	for (m_lIt = m_lLayers.begin(); m_lIt != m_lLayers.end(); ++m_lIt) {
		(*m_lIt)->Update(deltaTime);
	}


}

void Scene::Render(float deltaTime, const HDC & hDC)
{
	for (m_lIt = m_lLayers.begin(); m_lIt != m_lLayers.end(); ++m_lIt) 
		(*m_lIt)->Render(deltaTime, hDC);
	

}

//bool Scene::Init(const HDC & hDC)
//{
//	for (m_lIt = m_lLayers.begin(); m_lIt != m_lLayers.end(); ++m_lIt) {
//		if(!*m_lIt->Init())
//			return false;
//	}
//
//
//	
//}


void Scene::AddLayer(Layer * layer)
{
	m_lLayers.push_back(layer);
	if (m_lLayers.size() > 1)
		m_lLayers.sort(CompareLayer);

}

bool Scene::DeleteLayer(const std::string layerTag) {

	for (m_lIt = m_lLayers.begin(); m_lIt != m_lLayers.end(); ++m_lIt) {
		if ((*m_lIt)->GetLayerTag() == layerTag)
			delete *m_lIt;
			m_lLayers.erase(m_lIt);
	}
	
	return false;
}

Layer * Scene::CreateLayer(const std::string & layerTag, unsigned int order)
{
	Layer* temp = new Layer(layerTag, order);
	if (!temp->Init())
		return nullptr;

	m_lLayers.push_back(temp);
	
	if(m_lLayers.size() > 1)
		m_lLayers.sort(CompareLayer);

	return temp;
}

Layer * Scene::FindLayer(const std::string & layerTag)
{	
	for (m_lIt = m_lLayers.begin(); m_lIt != m_lLayers.end(); ++m_lIt)
		if ((*m_lIt)->GetLayerTag() == layerTag)
			return *m_lIt;

	return nullptr;
}

bool Scene::CompareLayer(const Layer* layer1, const Layer* layer2) { 

	return (layer1->GetLayerOrder() < layer2->GetLayerOrder()); 

}
