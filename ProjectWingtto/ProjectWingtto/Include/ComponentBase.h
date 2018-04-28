//모든 컴포넌트들의 기본 추상클래스

#pragma once

#include "../pch.h"


class ComponentBase {
public:
	ComponentBase() = default;
	virtual ~ComponentBase() = 0 { }

public:
	//Init에서 Owner 등록
	virtual bool Init(class Object* object) = 0;
	virtual void Update(const float& deltaTime) = 0;
	const std::string& GetName() const { return m_strName; }
	void SetComponentName(const std::string& name) { m_strName = name; }


protected:
	std::string m_strName;


};
