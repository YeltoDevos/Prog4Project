#include <iomanip>
#include <sstream>
#include "FPSComponent.h"
#include "GameObject.h"
#include "TextComponent.h"

dae::FPSComponent::FPSComponent(GameObject& parent):
	BaseComponent(parent)
{
}

void dae::FPSComponent::Update(const float deltaTime)
{
	m_duration += deltaTime;

	constexpr float updateFrequency{ 0.5f };

	if (m_duration < updateFrequency)
	{
		++m_framecount;
		return;
	}

	auto textComponent{ m_owner.GetComponent<dae::TextComponent>() };

	if (textComponent != nullptr)
	{
		const float fps{static_cast<float>(m_framecount) / m_duration };

		std::stringstream ssfps;
		ssfps << std::fixed << std::setprecision(2) << fps;
		const std::string fpsString{ ssfps.str() };
		
		if(fpsString != m_text)
		{
			textComponent->SetText(fpsString + " FPS");
			m_text = fpsString;
		}
	}

	m_framecount = 0;
	m_duration -= updateFrequency;
}



