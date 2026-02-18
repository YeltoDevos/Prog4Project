#include <string>
#include "Component.h"
#include "Renderer.h"
#include "ResourceManager.h"

dae::BaseComponent::BaseComponent()
{

}

dae::TextComponent::TextComponent(std::string text):
	m_Text{text}
{

}

std::string dae::TextComponent::GetText()
{
	return m_Text;
}

dae::RenderComponent::RenderComponent()
{
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	m_font = std::move(font);

	const auto surf = TTF_RenderText_Blended(m_font->GetFont(), m_text.c_str(), m_text.length(), m_color);
	auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
	SDL_DestroySurface(surf);
	m_textTexture = std::make_shared<Texture2D>(texture);

}

void dae::RenderComponent::Render()
{
	const auto& pos = m_transform.GetPosition();
	Renderer::GetInstance().RenderTexture(*m_textTexture, pos.x, pos.y);
}
