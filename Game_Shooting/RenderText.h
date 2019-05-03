
#include "Texture.h"
class RenderText :  public Texture
{
public:
	Graphics* graphics;
	RenderText();
	RenderText(string text, string fontPath, int size);
	~RenderText();

	virtual void render();
};
