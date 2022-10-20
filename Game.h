#include <chrono>

class Game{

public:
    void Run();
    virtual ~Game() = default;

private:
    virtual void OnKeyPressed(int btnCode) = 0;
    virtual void UpdateGame(double dt) = 0;
    virtual bool EndGame() = 0;

    using Clock = std::chrono::system_clock;
    using Time = std::chrono::time_point<Clock>;
};