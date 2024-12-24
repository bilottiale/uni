# Install and load the rpart package
install.packages("rpart")
library(rpart)

# Load the iris dataset
data(iris)

# Fit a decision tree model to predict Species based on other variables
model <- rpart(Species ~ ., data = iris, method = "class")

# Print the model summary
print(model)

# Visualize the decision tree
plot(model)
text(model)
