from typing import List


class Box:
    def __init__(self, width: int, height: int):
        self.width: int = width
        self.height: int = height
        # List of indices of boxes this box fits in
        self.fits_in: List[int] = []

        # Is visited on this DFS search?
        self.visited: bool = False
    
    def to_str(self):
        return f"({self.width}, {self.height}){self.fits_in}, "


def max_nest_level(boxes: List[Box]):
    for box_a in boxes:
        for i_b, box_b in enumerate(boxes):
            if fits_in(box_a, box_b):
                box_a.fits_in.append(i_b)

    max_depth = 0

    for box in boxes:
        print(box.to_str())

    for i in range(len(boxes)):
        # for box in boxes:
        #     box.visited = False

        max_depth = max(max_depth, dfs_depth(i, boxes))

    return max_depth


def dfs_depth(start_i: int, graph: List[Box]) -> int:
    # if graph[start_i].visited:
    #     return 1
    
    # graph[start_i].visited = True

    max_depth = 0
    for adj in graph[start_i].fits_in:
        max_depth = max(max_depth, dfs_depth(adj, graph))
    
    return max_depth + 1


def fits_in(a: Box, b: Box) -> int:
    a_min = min(a.width, a.height)
    a_max = max(a.width, a.height)
    b_min = min(b.width, b.height)
    b_max = max(b.width, b.height)
    return a_min < b_min and a_max < b_max


def test():
    boxes = [Box(1, 1), Box(2, 2), Box(3, 3)]
    print(max_nest_level(boxes))


test()
