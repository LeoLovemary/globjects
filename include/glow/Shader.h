#pragma once

#include <glow/Object.h>
#include <glow/ShaderFile.h>

#include <string>
#include <set>

// http://www.opengl.org/wiki/Shader

namespace glow {

class Program;

class Shader : public Object
{
	friend class Program;
public:
	Shader(GLenum type);
	~Shader();

	GLenum type() const;

	void setSource(const std::string& source, bool compile = true);
	const std::string& source() const;

	void setSourceFile(ShaderFile* sourceFile, bool compile = true);

	void compile();
	bool isCompiled() const;

	std::string infoLog() const;
protected:
	void checkCompileStatus();
	std::string typeString();
protected:
	GLenum _type;
	bool _compiled;
	std::string _source;
	ref_ptr<ShaderFile> _sourceFile;
	std::set<Program*> _programs;

	void addToProgram(Program* program);
	void removeFromProgram(Program* program);
};

} // namespace glow
