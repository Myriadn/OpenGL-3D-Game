#pragma once
#include <memory>

class OWindows;
class OGame
{
public:
	OGame();
	~OGame();

	void run();
	void quit();

protected:
	bool m_isRunning = true;
	std::unique_ptr<OWindows> m_display;
};

