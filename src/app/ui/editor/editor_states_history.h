// Aseprite
// Copyright (C) 2001-2016  David Capello
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.

#pragma once

#include "app/ui/editor/editor_state.h"

#include <vector>

namespace app {

  // Stack of states in the editor. The top state is the current state
  // of the editor.
  class EditorStatesHistory {
  public:
    EditorStatesHistory();
    ~EditorStatesHistory();

    bool empty() const { return m_states.empty(); }

    // Gets the current state.
    EditorStatePtr top();

    // Adds a new state in the history.
    void push(const EditorStatePtr& state);

    // Removes a state from the history (you should keep a reference of
    // the state with top() if you want to keep it in memory).
    void pop();

    // Deletes all the history.
    void clear();

  private:
    // Stack of states (the back of the vector is the top of the stack).
    std::vector<EditorStatePtr> m_states;
  };

} // namespace app

//The play once crashing patch is licensed under GPL thanks to @decap permission https://github.com/LibreSprite/LibreSprite/pull/476#issuecomment-2140727827
