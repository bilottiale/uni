set.seed(123)
n_simulations <- 1000 
final_holders <- numeric(6) 

for (sim in 1:n_simulations) {   
  current_holder <- 1   
  
  # Normalizzazione probabilità
  marbles <- sample(c("red", "blue"), 5005 + 5000, replace = TRUE, 
                    prob = c(5005/(5005 + 5000), 5000/(5005 + 5000)))      
  for (marble in marbles) {     
    if (marble == "red") {       
      current_holder <- ifelse(current_holder == 6, 1, current_holder + 1)  # Sposta a sinistra
    } else {       
      current_holder <- ifelse(current_holder == 1, 6, current_holder - 1)  # Sposta a destra
    }   
  }      
  
  final_holders[current_holder] <- final_holders[current_holder] + 1 
}  

# Normalizzazione
pmf <- final_holders / n_simulations 
print(pmf)
pmf_percent <- pmf * 100

# Barplot
barplot(
  pmf_percent,    
  names.arg = 1:6,    
  col = "blue",    
  main = "Estimated PMF of Final Holder of Spaghetti",   
  xlab = "Person Number",    
  ylab = "Probability (%)", 
)

for(holder in final_holders) {
  print(paste("La probabilità che il portaspaghetti finale sia", holder, "è", pmf[holder]))
}

print(paste("La somma di pmf è", sum(pmf)))