#include "RenderComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Texture2D.h"

dae::RenderComponent::RenderComponent(GameObject& parent):
	BaseComponent(parent)
{

}

void dae::RenderComponent::Update(const float)
{ 

}

void dae::RenderComponent::Render()
{
	if (m_textTexture != nullptr)
	{
		const auto& pos = m_transform.GetPosition();
		Renderer::GetInstance().RenderTexture(*m_textTexture, pos.x, pos.y);
	}
}

void dae::RenderComponent::SetTexture(std::shared_ptr<dae::Texture2D> Texture)
{
	m_textTexture = Texture;
}