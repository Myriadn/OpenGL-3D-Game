#pragma once

class OWindows
{
public:
	OWindows();
	~OWindows();

	void onDestroy();
	bool isClosed();

private:
	void* m_handle = nullptr;
};

