#include "RenderComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Texture2D.h"

dae::RenderComponent::RenderComponent(GameObject& parent):
	BaseComponent(parent)
{
}

void dae::RenderComponent::Update()
{ 
	//auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	//std::string text{ "renderer update" };
	//SDL_Color color{ 255, 255, 255, 255 };

	//const auto surf = TTF_RenderText_Blended(font->GetFont(), text.c_str(), text.length(), color);
	//auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
	//SDL_DestroySurface(surf);

	//auto temp = std::make_shared<Texture2D>(texture);

	//m_textTexture.swap(temp);
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