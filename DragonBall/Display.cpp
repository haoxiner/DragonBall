#include "Display.h"
#include "Input.h"
#include <sstream>

Display::Display()
  :window_(nullptr), running_(false), lastTick_(0), elapsedSeconds_(0), frameCount_(0)
{
}

Display::~Display()
{
}

bool Display::Initialize()
{
  if (!glfwInit())
  {
    return false;
  }
  glfwWindowHint(GLFW_SAMPLES, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  window_ = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window_)
  {
    glfwTerminate();
    return false;
  }
  glfwMakeContextCurrent(window_);
  glewExperimental = true;
  if (glewInit() != GLEW_OK)
  {
    glfwTerminate();
    return false;
  }
  
  bool *pRunning = &running_;
  glfwSetKeyCallback(window_, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
    /*  The action is one of GLFW_PRESS, GLFW_REPEAT or GLFW_RELEASE.
    *  The key will be GLFW_KEY_UNKNOWN if GLFW lacks a key token for it,
    *  for example E-mail and Play keys.
    */
    if (action == GLFW_PRESS)
    {
      switch (key)
      {
      case GLFW_KEY_W:
        Input::SetLeftTriggerY(Input::GetLeftTriggerY() + 1.0f);
        break;
      case GLFW_KEY_S:
        Input::SetLeftTriggerY(Input::GetLeftTriggerY() - 1.0f);
        break;
      case GLFW_KEY_A:
        Input::SetLeftTriggerX(Input::GetLeftTriggerX() - 1.0f);
        break;
      case GLFW_KEY_D:
        Input::SetLeftTriggerX(Input::GetLeftTriggerX() + 1.0f);
        break;
      default:
        break;
      }
    }
    else if (action == GLFW_RELEASE)
    {
      switch (key)
      {
      case GLFW_KEY_W:
        Input::SetLeftTriggerY(Input::GetLeftTriggerY() - 1.0f);
        break;
      case GLFW_KEY_S:
        Input::SetLeftTriggerY(Input::GetLeftTriggerY() + 1.0f);
        break;
      case GLFW_KEY_A:
        Input::SetLeftTriggerX(Input::GetLeftTriggerX() + 1.0f);
        break;
      case GLFW_KEY_D:
        Input::SetLeftTriggerX(Input::GetLeftTriggerX() - 1.0f);
        break;
      default:
        break;
      }
    }
  });
  running_ = true;
  return true;
}

void Display::Update()
{
  unsigned long tick = GetTickCount();
  if (tick < lastTick_)
  {
    tick = lastTick_;
  }
  delta_ = 0.001f * static_cast<float>(tick - lastTick_);
  elapsedSeconds_ += delta_;
  frameCount_++;
  if (elapsedSeconds_ >= 1.0f)
  {
    std::ostringstream oss;
    oss << frameCount_ / elapsedSeconds_;
    glfwSetWindowTitle(window_, oss.str().c_str());
    frameCount_ = 0;
    elapsedSeconds_ = 0.0f;
  }
  
  lastTick_ = tick;
  glfwSwapBuffers(window_);
  glfwPollEvents();
}

void Display::Destroy()
{
  glfwTerminate();
  window_ = nullptr;
  running_ = false;
}