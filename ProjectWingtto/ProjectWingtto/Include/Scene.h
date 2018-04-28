//제작하게 될 Scene들의 Interface
//Layer클래스들을 이용해서 GameObejct들을 관리한다.

#pragma once

#include "../pch.h"

class Layer;

class Scene {
public:
	Scene();
	virtual ~Scene();


public:
	virtual bool Init();
	virtual void Update(float deltaTime);
	virtual void Render(float deltaTime, const HDC& hDC);
	inline bool IsChangeScene() const { return m_bChangeScene;	}
	
	//아래부터는 Layer 관리 관련된 Method들
	virtual void AddLayer(Layer* layer);
	virtual bool DeleteLayer(const std::string layerTag);
	virtual Layer* CreateLayer(const std::string& layerTag, unsigned int order = 0);
	virtual Layer* FindLayer(const std::string& layerTag);


protected:
	inline void SetChangeScene(bool bChange) { m_bChangeScene = bChange; }


private:
	static bool CompareLayer(const Layer* layer1, const Layer* layer2);


protected:
	//Object들을 관리하는 Layer객체들의 List
	std::list<Layer*>						m_lLayers;
	std::list<Layer*>::iterator			m_lIt;


private:
	bool									m_bChangeScene;


};