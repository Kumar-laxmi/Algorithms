def flood_fill(image, sr, sc, new_color, original_color):
    # Base case: If the current cell is out of bounds or has already been filled with the new color
    if sr < 0 or sr >= len(image) or sc < 0 or sc >= len(image[0]) or image[sr][sc] != original_color:
        return

    # Update the current cell with the new color
    image[sr][sc] = new_color

    # Recursively fill the neighboring cells in all four directions
    flood_fill(image, sr + 1, sc, new_color, original_color)
    flood_fill(image, sr - 1, sc, new_color, original_color)
    flood_fill(image, sr, sc + 1, new_color, original_color)
    flood_fill(image, sr, sc - 1, new_color, original_color)


if __name__ == "__main__":
    # Sample image represented as a 2D list
    image = [
        [1, 1, 1, 1],
        [1, 1, 0, 1],
        [1, 0, 1, 0],
        [1, 0, 1, 0],
    ]

    sr = 1          # Starting row
    sc = 1          # Starting column
    new_color = 2   # New color to be filled

    original_color = image[sr][sc]  # Store the original color for comparison

    # Perform the flood fill algorithm
    flood_fill(image, sr, sc, new_color, original_color)

    # Print the updated image
    for row in image:
        print(" ".join(map(str, row)))
