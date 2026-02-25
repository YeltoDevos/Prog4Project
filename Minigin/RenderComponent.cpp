#include "RenderComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Texture2D.h"
#include "GameObject.h"
#include "TranslateComponents.h"

dae::RenderComponent::RenderComponent(GameObject& owner):
	BaseComponent(owner)
{

}

void dae::RenderComponent::Update(const float)
{ 

}

void dae::RenderComponent::Render()
{
	if (m_textTexture != nullptr)
	{
		const auto& transform{ m_owner.GetComponent<dae::TransformComponent>() };

		//const auto& pos = m_transform.GetPosition();

		if(transform != nullptr)
		{
			Renderer::GetInstance().RenderTexture(*m_textTexture, transform->GetPosition().x, transform->GetPosition().y);
		}
		else
		{
			Renderer::GetInstance().RenderTexture(*m_textTexture, 0.f, 0.f);
		}
	}
}

void dae::RenderComponent::SetTexture(std::shared_ptr<dae::Texture2D> Texture)
{
	m_textTexture = Texture;
}