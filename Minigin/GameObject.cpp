#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

#include "RenderComponent.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Test()
{

}

void dae::GameObject::Update(const float deltaTime) 
{
	for (auto& component : m_components)
	{
		component->Update(deltaTime);
	}
}

void dae::GameObject::Render() const
{
	for (auto& component : m_components)
	{
		auto ptr{ dynamic_cast<RenderComponent*>(component.get()) };

		if (ptr != nullptr)
		{
			component->Render();
		}
	}
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

//template <typename T>
//void dae::GameObject::AddComponent()
//{
//	m_components.push_back(std::make_shared<T>());
//}

//template<typename T>
//void dae::GameObject::RemoveComponent()
//{
//	for (auto component : m_components)
//	{
//		bool check{ dynamic_cast<t>(component) };
//		if (check)
//		{
//			return true;
//		}
//	}
//
//	std::ranges::remove_if(m_components, [](std::shared_ptr<basecomponent> component) {
//		if (dynamic_cast<t>(component) != nullptr)
//		{
//			return true;
//		}
//		});
//}

//template<typename T>
//std::shared_ptr<T> dae::GameObject::GetComponent()
//{
//	auto iterator = std::ranges::find_if(m_components, [](std::shared_ptr<BaseComponent> component) {
//		if (dynamic_cast<T>(component) != nullptr)
//		{
//			return true;
//		}
//		});
//
//	if (iterator == m_components.end())
//	{
//		return nullptr;
//	}
//	else
//	{
//		return dynamic_cast<T>(m_components[iterator]);		
//	}
//}

//template<typename T>
//bool dae::GameObject::CheckComponent()
//{
//	//for (auto component : m_components)
//	//{
//	//	bool check{ dynamic_cast<T>(component) };
//	//	if (check)
//	//	{
//	//		return true;
//	//	}
//	//}
//
//	return std::ranges::any_of(m_components, [](std::shared_ptr<BaseComponent> component) {
//		if (dynamic_cast<T>(component) != nullptr)
//		{
//			return true;
//		}
//		});
//
//	return false;
//}
