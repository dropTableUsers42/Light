#include "Cube.hpp"

Cube::Cube(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
    : SceneObject({
                      {Light::ShaderDataType::Float3, "a_Position"},
                      {Light::ShaderDataType::Float4, "a_Color"},
                      {Light::ShaderDataType::Float3, "a_Normal"}
                  }),
      m_position(position),
      m_rotation(rotation),
      m_scale(scale)
{
    m_shader = Light::Shader::create("../Light/assets/shaders/phong.glsl");
    m_vao.reset(Light::VertexArray::create());

    float vertices[] = {
        //Front
        -0.5, -0.5, 0.5, 0.8, 0.8, 0.8, 1.0, 0, 0, 1.0,
        0.5, -0.5, 0.5, 0.8, 0.8, 0.8, 1.0, 0, 0, 1.0,
        0.5, 0.5, 0.5, 0.8, 0.8, 0.8, 1.0, 0, 0, 1.0,
        -0.5, 0.5, 0.5, 0.8, 0.8, 0.8, 1.0, 0, 0, 1.0,
        //Left
        -0.5, -0.5, 0.5, 0.8, 0.8, 0.8, 1.0, -1.0, 0, 0,
        -0.5, 0.5, 0.5, 0.8, 0.8, 0.8, 1.0, -1.0, 0, 0,
        -0.5, 0.5, -0.5, 0.8, 0.8, 0.8, 1.0, -1.0, 0, 0,
        -0.5, -0.5, -0.5, 0.8, 0.8, 0.8, 1.0, -1.0, 0, 0,
        //Right
        0.5, -0.5, 0.5, 0.8, 0.8, 0.8, 1.0, 1.0, 0, 0,
        0.5, -0.5, -0.5, 0.8, 0.8, 0.8, 1.0, 1.0, 0, 0,
        0.5, 0.5, -0.5, 0.8, 0.8, 0.8, 1.0, 1.0, 0, 0,
        0.5, 0.5, 0.5, 0.8, 0.8, 0.8, 1.0, 1.0, 0, 0,
        //Top
        -0.5, 0.5, 0.5, 0.8, 0.8, 0.8, 1.0, 0, 1.0, 0,
        0.5, 0.5, 0.5, 0.8, 0.8, 0.8, 1.0, 0, 1.0, 0,
        0.5, 0.5, -0.5, 0.8, 0.8, 0.8, 1.0, 0, 1.0, 0,
        -0.5, 0.5, -0.5, 0.8, 0.8, 0.8, 1.0, 0, 1.0, 0,
        //Bottom
        -0.5, -0.5, 0.5, 0.8, 0.8, 0.8, 1.0, 0, -1.0, 0,
        -0.5, -0.5, -0.5, 0.8, 0.8, 0.8, 1.0, 0, -1.0, 0,
        0.5, -0.5, -0.5, 0.8, 0.8, 0.8, 1.0, 0, -1.0, 0,
        0.5, -0.5, 0.5, 0.8, 0.8, 0.8, 1.0, 0, -1.0, 0,
        //Back
        -0.5, -0.5, -0.5, 0.8, 0.8, 0.8, 1.0, 0, 0, -1.0,
        -0.5, 0.5, -0.5, 0.8, 0.8, 0.8, 1.0, 0, 0, -1.0,
        0.5, 0.5, -0.5, 0.8, 0.8, 0.8, 1.0, 0, 0, -1.0,
        0.5, -0.5, -0.5, 0.8, 0.8, 0.8, 1.0, 0, 0, -1.0,
    };

    m_vbo.reset(Light::VertexBuffer::create(vertices, sizeof(vertices)));
    m_vbo->setLayout(m_layout);

    unsigned int indices[] = {
        0, 1, 2, 2, 3, 0,
        4, 5, 6, 6, 7, 4,
        8, 9, 10, 10, 11, 8,
        12, 13, 14, 14, 15, 12,
        16, 17, 18, 18, 19, 16,
        20, 21, 22, 22, 23, 20
    };

    m_ibo.reset(Light::IndexBuffer::create(indices,
                                           sizeof(indices)
                                               / sizeof(unsigned int)));

    m_vao->addVertexBuffer(m_vbo);
    m_vao->setIndexBuffer(m_ibo);

    updateTransform();
}

void Cube::onUpdate(Light::Timestep ts)
{
    if (Light::Input::isKeyPressed(LIGHT_KEY_A))
    {
        m_position.x -= 1.0f * ts.getSeconds();
    } else if (Light::Input::isKeyPressed(LIGHT_KEY_D))
    {
        m_position.x += 1.0f * ts.getSeconds();
    } else if (Light::Input::isKeyPressed(LIGHT_KEY_W))
    {
        m_position.z += 1.0f * ts.getSeconds();
    } else if (Light::Input::isKeyPressed(LIGHT_KEY_S))
    {
        m_position.z -= 1.0f * ts.getSeconds();
    } else if (Light::Input::isKeyPressed(LIGHT_KEY_1))
    {
        m_rotation.x += 20.0f * ts.getSeconds();
    } else if (Light::Input::isKeyPressed(LIGHT_KEY_2))
    {
        m_rotation.x -= 20.0f * ts.getSeconds();
    } else if (Light::Input::isKeyPressed(LIGHT_KEY_3))
    {
        m_scale += 0.2f * ts.getSeconds();
    } else if (Light::Input::isKeyPressed(LIGHT_KEY_4))
    {
        m_scale -= 0.2 * ts.getSeconds();
    }

    updateTransform();
}

void Cube::onEvent(Light::Event &e)
{

}

void Cube::render()
{
    Light::Renderer::submit(m_shader, m_vao, m_transform);
}

void Cube::updateTransform()
{
    m_transform = glm::translate(glm::mat4(1.0f), m_position);
    m_transform = glm::scale(m_transform, m_scale);
    m_transform = glm::rotate(m_transform,
                              glm::radians(m_rotation.x),
                              glm::vec3(1.0, 0.0, 0.0));
    m_transform = glm::rotate(m_transform,
                              glm::radians(m_rotation.y),
                              glm::vec3(0.0, 1.0, 0.0));
    m_transform = glm::rotate(m_transform,
                              glm::radians(m_rotation.z),
                              glm::vec3(0.0, 0.0, 1.0));
}