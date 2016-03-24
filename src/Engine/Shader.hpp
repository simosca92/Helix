#include <GL/glew.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Helix {
    class Shader {
        public:
            Shader();
            Shader(std::string vertexShaderFile, std::string fragmentShaderFile, std::string shaderName);
            ~Shader();

            void loadShader(std::string vertexShaderFile, std::string fragmentShaderFile, std::string shaderName);
            void UseShader(std::string shaderName);
            GLuint GetShader(std::string shaderName);
            
            //should be removed (move code to game)
            void InitPyro(std::string shaderName, float time, glm::mat4 view, glm::mat4 projection);
            
         private:
            GLuint readShader(std::string shaderFile, GLenum shaderType);
            //move m_loadedShaders outside?
            std::map<std::string,GLuint> m_loadedShaders;
            
            //should be removed (move code to game)
            glm::mat4 projection;
            glm::mat4 view;
            GLint uniform_m_mvp;
    };  
}
