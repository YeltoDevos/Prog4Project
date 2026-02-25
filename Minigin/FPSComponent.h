#pragma once
#include <chrono>
#include "Component.h"

namespace dae
{
	class FPSComponent : public BaseComponent
	{
	public:
		FPSComponent(GameObject& parent);

		virtual void Update(const float deltaTime) override;


	private:
		std::string m_text{};

		float m_duration{};
		int m_framecount{};
	};

}
