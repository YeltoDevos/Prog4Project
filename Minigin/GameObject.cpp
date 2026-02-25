#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "RenderComponent.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::SetParent(GameObject* parent)
{
	if (IsChild(parent) || parent == this || m_parent == parent)
		return;
	//if(parent == nullptr)


	if (m_parent) m_parent->RemoveChild(this);
	m_parent = parent;
	if (m_parent) m_parent->AddChild(this);

}

void dae::GameObject::AddChild(GameObject* child)
{
	m_Children.emplace_back(child);
}

void dae::GameObject::RemoveChild(GameObject* child)
{
	std::erase_if(m_Children, [child](GameObject* c) {
		return c == child;
		});
}

bool dae::GameObject::IsChild(GameObject* child)
{
	//return std::ranges::any_of(m_Children, [child](GameObject* c) {
	//	return child == c;
	//	});

	for (GameObject* c : m_Children)
	{
		if (c == child)
			return true;
	}
	return false;
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
