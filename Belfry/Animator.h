#pragma once

#include <GLFW/glfw3.h>
#include <vector>
#include <algorithm>
#include <assert.h> 
#include "BlfComponent.h"
#include "Animation.h"

class Animator : public BlfComponent {
public:
  const void awake() {
    animationChain[0]->isPlaying = true;
    startTime = currentTime();
  }

  const void update() {
    if (animationFinished()) {
      playNextAnimation();
    } else {
      currentlyPlayingAnimation()->animate(this->parent());
    }
  }

  void addToChain(Animation* animation) {
    animationChain.push_back(animation);
  }

private:
  std::vector<Animation*> animationChain;
  float startTime;

  GLfloat currentTime() {
    return (GLfloat) glfwGetTime();
  }

  bool animationFinished() {
    GLfloat animationTime = currentlyPlayingAnimation()->length;
    bool finished = startTime + animationTime < currentTime();

    return finished;
  }

  void playNextAnimation() {
    auto animationIndex = std::distance(animationChain.begin(), std::find(animationChain.begin(), animationChain.end(), currentlyPlayingAnimation()));
    auto nextAnimationIndex = (animationIndex + 1) % animationChain.size();

    assert(nextAnimationIndex < animationChain.size());

    currentlyPlayingAnimation()->isPlaying = false;
    animationChain[nextAnimationIndex]->isPlaying = true;
    startTime = currentTime();
  }

  Animation* currentlyPlayingAnimation() {
    Animation* playingAnimation = NULL;

    for (int i = 0; i < animationChain.size(); i++)
      if (animationChain[i]->isPlaying) {
        playingAnimation = animationChain[i];
        break;
      }

    assert(playingAnimation != NULL);

    return playingAnimation;
  }
};