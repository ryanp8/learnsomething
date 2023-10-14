def max_area(height):
    max_area = 0
    n = len(height)

    l = 0
    r = n - 1
    while l < r:
        width = r - l
        max_area = max(min(height[l], height[r]) * width, max_area)
        if height[r] > height[l]:
            l += 1
        else:
            r -= 1

    return max_area