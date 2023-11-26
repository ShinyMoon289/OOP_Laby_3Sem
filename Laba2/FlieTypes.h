#pragma once
#include<iostream>

class graphFile
{
protected:
	static unsigned int Count;
	std::string Name;
	unsigned int Size;
public:
	graphFile();
	graphFile(const graphFile& obj);
	graphFile(std::string, unsigned int);
	~graphFile() { this->Count--; }
	std::string getName();
	void setName(std::string newname);
	unsigned int showCounter();
	unsigned int getSize();
	void setSize(unsigned int newsize);
};


unsigned int graphFile::showCounter()
{
	return Count;
}
graphFile::graphFile(std::string newname, unsigned int newsize)
{
	this->Name = newname;
	this->Size = newsize;
	this->Count++;
}
graphFile::graphFile(const graphFile& obj)
{
	this->Name = obj.Name;
	this->Size = obj.Size;
	this->Count++;
}
graphFile::graphFile()
{
	this->Name = " ";
	this->Size = 42;
	this->Count++;
}

std::string graphFile::getName()
{
	return this->Name;
}
void graphFile::setName(std::string newname)
{
	this->Name = newname;
}

unsigned int graphFile::getSize()
{
	return this->Size;
}
void graphFile::setSize(unsigned int newsize)
{
	this->Size = newsize;
}


class pngFile :public graphFile
{
protected:
	unsigned int Pixels;
public:
	pngFile();
	pngFile(const pngFile&);
	pngFile(std::string, unsigned int, unsigned int);
	~pngFile() { this->Count--; }
	unsigned int getPixels();
	void setPixels(unsigned int newpixels);
};

pngFile::pngFile()
{
	Name = " ";
	Size = 42;
	Pixels = 1080;
}

pngFile::pngFile(const pngFile& obj)
{
	Name = obj.Name;
	Size = obj.Size;
	Pixels = obj.Pixels;
}

unsigned int pngFile::getPixels()
{
	return this->Pixels;
}
void pngFile::setPixels(unsigned int newpixels)
{
	this->Pixels = newpixels;
}

pngFile::pngFile(std::string newname, unsigned int newsize,unsigned int newpixels)
{
	Name = newname;
	Size = newsize;
	Pixels = newpixels;
}

class svgFile :public graphFile
{
protected:
	unsigned int Dots;
public:
	svgFile();
	svgFile(std::string , unsigned int , unsigned int);
	svgFile(const svgFile&);
	~svgFile() { Count--; }
	unsigned int getDots();
	void setDots(unsigned int newdots);
};

svgFile::svgFile(std::string newname, unsigned int newsize, unsigned int newdots)
{
	Name = newname;
	Size = newsize;
	Dots=newdots;
}
svgFile::svgFile()
{
	Name = " ";
	Size = 42;
	Dots = 54564;
}

svgFile::svgFile(const svgFile& obj)
{
	Name = obj.Name;
	Size = obj.Size;
	Dots = obj.Dots;
}

unsigned int svgFile::getDots()
{
	return this->Dots;
}
void svgFile::setDots(unsigned int newdots)
{
	this->Dots = newdots;
}

template<class Tp=std::string> class Logo :public svgFile
{
protected:
	Tp picture;
public:
	Logo();
	Logo(std::string, unsigned int,unsigned int,Tp);
	Logo(const Logo&);
	~Logo() { Count--; }
	Tp getPicture();
	void setPicture(Tp newpicture);
};

template<class Tp>
Logo<Tp>::Logo()
{
	Name = " ";
	Size = 6356;
	Dots = 534645;
	picture = "painting";
}

template<class Tp>
Logo<Tp>::Logo(std::string newname, unsigned int newsize, unsigned int newdots, Tp newpicture)
{
	Name = newname;
	Size = newsize;
	Dots = newdots;
	picture = newpicture;
}

template<class Tp>
Logo<Tp>::Logo(const Logo& obj)
{
	Name = obj.Name;
	Size = obj.Size;
	Dots = obj.Dots;
	picture = obj.picture;
}

template<class Tp>
Tp Logo<Tp>::getPicture()
{
	return picture;
}
template<class Tp>
void Logo<Tp>::setPicture(Tp newpicture)
{
	picture = newpicture;
}

template<class Colors=char> class Painting :public pngFile
{
protected:
	Colors colors;
public:
	Colors getColors();
	void setColors(Colors newcolors);
};

template<class Colors>
Colors Painting<Colors>::getColors()
{
	return colors;
}
template<class Colors>
void Painting<Colors>::setColors(Colors newcolors)
{
	colors = newcolors;
}












