class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        stack = [(0, 0)]
        self.seen = set()
        while stack:
            nx, ny = stack.pop()
            if nx == z or ny == z or nx + ny == z:
                return True
            if (nx, ny) in self.seen:
                continue
            self.seen.add((nx, ny))
            stack.append((x, ny))
            stack.append((nx, y))
            stack.append((0, ny))
            stack.append((nx, 0))
            stack.append((nx - min(nx, y - ny), ny + min(nx, y - ny)))
            stack.append((nx + min(ny, x - nx), ny - min(ny, x - nx)))
        return False