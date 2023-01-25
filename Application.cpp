//Konrad Matusewicz
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Texture.h"
#include "Shader.h"
#include "VertexArray.h" 
#include "Renderer.h"
#include "VertexBufferLayout.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"

#define ASSERT(x) if (!(x)) __debugbreak();


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

  

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 800, "Carrera Streckeneditor", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    //First you need to create a valid OpenGL rendering context and call glewInit() to initialize the extension entry points. If glewInit() returns GLEW_OK, the initialization succeeded and you can use the available extensions as well as core OpenGL functionality. For example: 
    if (glewInit() != GLEW_OK)
        std::cout << "Error" << std::endl;

    //GPU Driver Version, OpenGL Version
    std::cout << glGetString(GL_VERSION) << std::endl;
    {
        float positions[] = {        //vertex Position
            -50.0f, -50.0f, 0.0f, 0.0f,   //0
             50.0f, -50.0f, 1.0f, 0.0f,  //1
             50.0f,  50.0f, 1.0f, 1.0f,  //2
            -50.0f,  50.0f, 0.0f, 1.0f    //3

        };
        // Index BUffer
        unsigned int indices[] = {
            0,1,2,
            2,3,0
        };

               glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
               glEnable(GL_BLEND);


        VertexArray va;

        VertexBuffer vb(positions, 4 * 4 * sizeof(float));

        VertexBufferLayout layout;
        layout.Push<float > (2);
        layout.Push<float >(2);
        va.AddBuffer(vb, layout);



        //Buffer Layer



        IndexBuffer ib(indices, 6);


        glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
       



        Shader shader("res/shaders/Basis.shader");
        shader.Bind();







        /*
        std::cout << "Vertex" << std::endl;
        std::cout << source.VertexSource << std::endl;
        std::cout << "Fragment" << std::endl;
        std::cout << source.FragmentSource << std::endl;
        */

        shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);


       
        va.Unbind();
        vb.Unbind();
        ib.Unbind();
        shader.Unbind();

        Renderer renderer;

     
        ImGui::CreateContext();
        ImGui_ImplGlfwGL3_Init(window, true);
        ImGui::StyleColorsDark();

        glm::vec3 translationA(200, 200, 0);
        glm::vec3 translationB(400, 200, 0);
        glm::vec3 translationC(400, 90, 0);
        glm::vec3 translationD(200, 90, 0);
        glm::vec3 translationE(400, 310, 0);
        glm::vec3 translationF(200, 310, 0);


        float r = 0.0f;

        float increment = 0.05f;
        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            renderer.Clear();

            ImGui_ImplGlfwGL3_NewFrame();




           
            shader.SetUniform4f("u_color", 0.8f, 0.3f, 0.8f, 1.0f);

            {
                glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
                glm::mat4 mvp = proj * view * model;
                shader.Bind();
                shader.SetUniformMat4f("u_MVP", mvp);
                Texture texture("res2/Textur/Kurve.png");
                texture.Bind();
                shader.SetUniform1i("u_Texture", 0);

                renderer.Draw(va, ib, shader);

            }
            

            {
                glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB);
                glm::mat4 mvp = proj * view * model;
                shader.Bind();
                shader.SetUniformMat4f("u_MVP", mvp);
                Texture texture("res2/Textur/Gerade.png");
                texture.Bind();
                shader.SetUniform1i("u_Texture", 0);


                renderer.Draw(va, ib, shader);
            }

            {
                glm::mat4 model = glm::translate(glm::mat4(1.0f), translationC);
                glm::mat4 mvp = proj * view * model;
                shader.Bind();
                shader.SetUniformMat4f("u_MVP", mvp);
                Texture texture("res2/Textur/Kurve2.png");
                texture.Bind();
                shader.SetUniform1i("u_Texture", 0);


                renderer.Draw(va, ib, shader);
            }

            {
                glm::mat4 model = glm::translate(glm::mat4(1.0f), translationD);
                glm::mat4 mvp = proj * view * model;
                shader.Bind();
                shader.SetUniformMat4f("u_MVP", mvp);
                Texture texture("res2/Textur/Gerade.png");
                texture.Bind();
                shader.SetUniform1i("u_Texture", 0);


                renderer.Draw(va, ib, shader);
            }

            {
                glm::mat4 model = glm::translate(glm::mat4(1.0f), translationE);
                glm::mat4 mvp = proj * view * model;
                shader.Bind();
                shader.SetUniformMat4f("u_MVP", mvp);
                Texture texture("res2/Textur/Kurve3.png");
                texture.Bind();
                shader.SetUniform1i("u_Texture", 0);


                renderer.Draw(va, ib, shader);
            }

            {
                glm::mat4 model = glm::translate(glm::mat4(1.0f), translationF);
                glm::mat4 mvp = proj * view * model;
                shader.Bind();
                shader.SetUniformMat4f("u_MVP", mvp);
                Texture texture("res2/Textur/Kurve4.png");
                texture.Bind();
                shader.SetUniform1i("u_Texture", 0);


                renderer.Draw(va, ib, shader);
            }

            //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);  //Zeichnen vom Buffer , Und wie viele Vertecies

            if (r > 1.0f)
                increment = -0.05f;
            else if (r < 0.0f)
                increment = 0.05f;

            r += increment;

            {
                ImGui::SliderFloat3("Translation A", &translationA.x, 0.0f, 960.0f);
                ImGui::SliderFloat3("Translation B", &translationB.x, 0.0f, 960.0f);
                ImGui::SliderFloat3("Translation C", &translationC.x, 0.0f, 960.0f);
                ImGui::SliderFloat3("Translation D", &translationD.x, 0.0f, 960.0f);
                ImGui::SliderFloat3("Translation E", &translationE.x, 0.0f, 960.0f);
                ImGui::SliderFloat3("Translation F", &translationF.x, 0.0f, 960.0f);
                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            }
           
            ImGui::Render();
            ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }

    
        ImGui_ImplGlfwGL3_Shutdown();
        ImGui::DestroyContext();

        glfwTerminate();
        return 0;
    }
}