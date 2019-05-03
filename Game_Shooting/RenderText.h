
#include "Texture.h"
class RenderText :  public Texture
{
public:
	Graphics* graphics;
	RenderText();
	RenderText(string text, string fontPath, int size, int x, int y);
	~RenderText();

	virtual void render();
};
