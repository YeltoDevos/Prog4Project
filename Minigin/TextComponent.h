#pragma once
#include "Component.h"

namespace dae
{
	class TextComponent : public BaseComponent
	{
	public:
		explicit TextComponent(GameObject& parent);

		virtual void Update() override;

		void SetText(const std::string& text);
		std::string GetText();
		std::shared_ptr<Texture2D> GetTexture();

	private:
		std::string m_text{ "TextComponent text" };
		SDL_Color m_color{ 255, 255, 255, 255 };
		std::shared_ptr<Font> m_font{};
		std::shared_ptr<Texture2D> m_textTexture{};
	};
}