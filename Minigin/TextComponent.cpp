#include "TextComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Texture2D.h"
#include "GameObject.h"
#include "RenderComponent.h"

dae::TextComponent::TextComponent(GameObject& parent):
	BaseComponent(parent)
{
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	m_font = std::move(font);

	SetText("Empty");
}

void dae::TextComponent::Update(const float)
{
	const auto renderer{ m_parent.GetComponent<dae::RenderComponent>() };
	if (renderer != nullptr)
	{
		renderer->SetTexture(m_textTexture);
	}
}

void dae::TextComponent::SetText(const std::string& text)
{
	const auto surf = TTF_RenderText_Blended(m_font->GetFont(), text.c_str(), text.length(), m_color);
	auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
	SDL_DestroySurface(surf);

	m_textTexture = std::make_shared<Texture2D>(texture);
}

std::string dae::TextComponent::GetText()
{
	return m_text;
}

std::shared_ptr<dae::Texture2D> dae::TextComponent::GetTexture()
{
	return m_textTexture;
}