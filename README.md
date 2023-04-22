# Ambix

A game engine with a novel rendering pipeline. Because if I never try to implement it, I'll never know how bad my idea is.

## The Rendering Pipeline

The Ambix engine renders scenes by organizing `renderable` objects into a tree structure separate from the normal object hierarchy. Finding the color of a ray corresponding to an individual pixel amounts to traversing a portion of this tree, which in turn amounts to evaluating the root node by calling the render() function on it.

Nodes in the render tree can be broadly categorized as "objects" (leaf nodes), or "groups" (branch nodes). The children must implement an interface defined alongside the group itself. The group is thus responsible for rendering its children and producing an output that its parent can interpret. Ultimately, the root node produces an RGB value. This lends itself to intuitive implementations and combinations of objects that are stored and rendered in dramatically different ways.

You may for example have two sets of objects handled by different rendering techniques, one optimized for objects whose meshes we may change on the fly and another for objects whose meshes remain static. Objects may be separated between ray-tracing acceleration structures optimized for static objects and acceleration structures acceleration structures optimized for objects which move frequently.