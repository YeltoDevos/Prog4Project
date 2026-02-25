#pragma once
#include <string>
#include <memory>
#include <ranges>
#include "Transform.h"
#include "Component.h"

namespace dae
{
	class Texture2D;
	class GameObject final
	{
		std::shared_ptr<Texture2D> m_texture{};
		std::vector<std::unique_ptr<BaseComponent>> m_components{};
		GameObject* m_parent{ nullptr };
		std::vector<GameObject*> m_Children{};

	public:
		void Update(const float deltaTime);
		void Render() const;

		void SetTexture(const std::string& filename);

		GameObject() = default;
		~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void SetParent(GameObject* parent);
		void AddChild(GameObject* child);
		void RemoveChild(GameObject* child);
		bool IsChild(GameObject* child);


		template <std::derived_from<BaseComponent> T>
		void AddComponent()
		{
			m_components.push_back(std::make_unique<T>(*this));
		}

		template <std::derived_from<BaseComponent> T>
		void RemoveComponent()
		{

		}

		template <std::derived_from<BaseComponent> T>
		T* GetComponent()
		{
			for (auto& component : m_components)
			{
				auto ptr{ dynamic_cast<T*>(component.get()) };

				if (ptr != nullptr)
				{
					return ptr;
				}
			}

			return nullptr;
		}

		template <std::derived_from<BaseComponent> T>
		bool CheckComponent()
		{
			for (const auto& component : m_components)
			{
				auto ptr{ std::dynamic_pointer_cast<T>(component) };

				if (ptr != nullptr)
				{
					return true;
				}
			}


			//return std::ranges::any_of(m_components, [](std::shared_ptr<BaseComponent> component) {
			//	if (std::dynamic_pointer_cast<T>(component) != nullptr)
			//	{
			//		return true;
			//	}
			//	});

			return false;
		}
	};
}
