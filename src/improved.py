def max_area(height):
    max_area = 0
    n = len(height)

    l = 0
    r = n - 1
    while l > r:
        width = r - l
        max_area = min(height[l], height[r]) * width
        if height[r] > height[l]:
            l += 1
        if height[l] > height[r]:
            r -= 1
    return max_area
