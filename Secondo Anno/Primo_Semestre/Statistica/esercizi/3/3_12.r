  # a. Say you start with a bankroll of $127. How many bets can you lose in a row without losing your bankroll?
  bankroll <- 127
  bet <- 1
  total_bet <- 0
  losses <- 0
  
  # Looping until the bankroll is 0
  while (total_bet + bet <= bankroll) {
    total_bet <- total_bet + bet
    bet <- bet * 2
    losses <- losses + 1
  }
  
  cat("Dopo", losses - 1, "perdite consecutive si è perso:", bankroll, "$\n")
  
  
  # b. If you have a $127 bankroll, what is the probability that bet doubling wins you $1?
  # Probability of losing a bet
  p_lose <- 10 / 19
  
  # Probability of losing 7 bets in a row
  p_lose_7 <- p_lose^7
  
  # Probability of winning at least once in 7 bets
  p_win_1 <- 1 - p_lose_7
  
  cat("La probabilità di vincere almeno una volta in 7 scommesse è:", p_win_1, "\n")
  
  
  # c. What is the expected value of the bet doubling strategy with a $127 bankroll?
  # Expected value
  ev <- (1 * p_win_1) + (-127 * p_lose_7)
  cat("Il valore atteso della strategia di raddoppio è:", ev, "$\n")
  
  
  # d. If you play the bet doubling strategy with a $127 bankroll, how many times can you expect to play before you lose your bankroll?
  # Expected number of plays before bankruptcy
  expected_plays <- 1 / p_lose_7
  cat("Il numero di giocate attese prima di andare in bancarotta è:", expected_plays, "\n")
