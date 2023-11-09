#include "Player.h"

// Creates two players, alternates turns until one player loses. That is all.
int main() {
	Player r(true);
	Player b(false);
	while (r.turn() && b.turn());
}