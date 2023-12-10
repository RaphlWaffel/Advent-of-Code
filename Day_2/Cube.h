class Cube {
  private:
    COLOR color_;
    int max_;
    int actual_;

  public:
  Cube(COLOR color, int max) : color_(color), max_(max) {}
    bool draw(int numbers) {
      return numbers <= max_;
    }

};

enum class COLOR {
  BLUE = 0,
  RED = 1,
  GREEN = 2,
  UNDEFINED = 3,
};