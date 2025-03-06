#include <stdio.h>
#include <vector>

// Global vars
int _X, _Y;
int _n;

// Pieces
std::vector<std::vector<int>> _pieces;
// Memoization (keep separate from pieces: if entry exists, surely is best value)
std::vector<std::vector<int>> _subProb;

//-----------------------------------------------------------------------------
bool readData() {
  bool hasPieces = false;
  // matrix dimensions
  scanf("%d %d", &_X, &_Y);
  // if needed: rotate Y to the biggest dimension
  if (_X > _Y) { int tmp = _X; _X = _Y; _Y = tmp; }

  // pieces matrix having +1 col/row, initialized with 0's
  _pieces.resize(_X+1);
  for (int i = 0; i <= _X; i++) _pieces[i].resize(_Y+1, 0);
  // results matrix having +1 col/row, initialized with -1's
  _subProb.resize(_X+1);
  for (int i = 0; i <= _X; i++) _subProb[i].resize(_Y+1, -1);

  // pieces dimensions
  scanf("%d", &_n);
  for (int i = 0; i < _n; i++) {
    int a, b, p;
    scanf("%d %d %d", &a, &b, &p);
    // Piece is only stored (directly in the matrix!) if it fits the matrix
    if (a <= _X && b <= _Y // non-rotated piece fits
        && p > _pieces[a][b]) { // and price better than previous
      _pieces[a][b] = p;
      hasPieces = true;
    }
    if (b <= _X && a <= _Y // rotated piece fits
        && p > _pieces[b][a]) { // and price better than previous
      _pieces[b][a] = p;
      hasPieces = true;
    }
  }
  return hasPieces;
}

//-----------------------------------------------------------------------------
int topDown(int i, int j) {
  // C(i,j) = max(C(i,j),
  //              max(C(i,k) + C(i,j-k), 1 <= k < j),
  //              max(C(k,j) + C(i-k,j), 1 <= k < i))
  if (i == 0 || j == 0) return 0;

  // SubProblem already computed
  if (_subProb[i][j] != -1) return _subProb[i][j];

  // if there's a piece with dimensions i,j
  int best = _pieces[i][j]; 

  // best horizontal cut (varying Ys): C(i,k) + C(i,j-k), 1 <= k < j
  for (int k = 1; 2*k <= j; k++) { // optimization: k only [1, j/2]
      int h = topDown(i, k) + topDown(i, j-k);
      if (h > best) best = h;
  }

  // best vertical cut (varying Xs): C(k,j) + C(i-k,j), 1 <= k < i
  for (int k = 1; 2*k <= i; k++) { // optimization: k only [1, i/2]
      int v = topDown(k, j) + topDown(i-k, j);
      if (v > best) best = v;
  }

  // save subproblem best solution
  _subProb[i][j] = best;
  if (j <= _X) // optimization
    _subProb[j][i]= best; // symmetric subproblem also solved
  return best;
}

//-----------------------------------------------------------------------------
int main() {
  if (readData())
    printf("%d\n", topDown(_X, _Y));
  else
    printf("0\n");
  return 0;
}
