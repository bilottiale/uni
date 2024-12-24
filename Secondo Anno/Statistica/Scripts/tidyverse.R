
## Title: The tidyverse
## Author: Luca La Rocca
## Date: 9 December 2024

## The tidyverse is an opinionated collection of R packages
## designed for data science. All packages share
## an underlying design philosophy, grammar, and data structures.
## https://www.tidyverse.org/

## library(tidyverse) # uncomment to load all tidyverse tools at once
library(dplyr) # main tidyverse package

## Sys.setLanguage("en", unset="it") # uncomment to disable message translation
rm(list=ls(all=TRUE)) # clean the workspace

cat("--------------------------", fill = TRUE)
cat("Motor Trend Car Road Tests", fill = TRUE)
cat("--------------------------", fill = TRUE)
str(mtcars)
print(mtcars)
cat("Extracting the first two columns gives a dataframe:", fill = TRUE)
print(head(mtcars[, 1:2]))
cat("Extracting the first column gives a vector:", fill = TRUE)
print(head(mtcars[, 1])) # type inconsistency

mtcars <- as_tibble(mtcars)
cat("--------------------------", fill = TRUE)
str(mtcars)
print(mtcars)
cat("Extracting the first two columns gives a tibble:", fill = TRUE)
print(mtcars[, 1:2])
cat("Extracting the first column gives a tibble:", fill = TRUE)
print(mtcars[, 1]) # type consistency

cat("--------------", fill = TRUE)
cat("MovieLens 100K", fill = TRUE)
cat("--------------", fill = TRUE)

movies <- as_tibble(fosdata::movies)
print(movies)

cat("The dplyr package is organized around commands called verbs.", fill = TRUE)
cat("We consider 8 of them:", fill = TRUE)

cat("1) filter()", fill=TRUE)
cat("e.g. filter to find all the half-star ratings", fill = TRUE)
print(filter(movies, rating != round(rating)))

cat("2) select()", fill=TRUE)
cat("e.g. select the columns rating and movieId (in that order)", fill = TRUE)
print(select(movies, rating, movieId))

cat("3) arrange()", fill=TRUE)
cat("e.g. arrange the ratings in descending order of rating", fill = TRUE)
print(arrange(movies, desc(rating)))

cat("4) slice_max()", fill=TRUE)
cat("e.g. find the last five reviews (by timestamp) in the data", fill = TRUE)
print(slice_max(movies, n = 5, timestamp))

cat("5) slice_min()", fill=TRUE)
cat("e.g. find the first five reviews (by timestamp) in the data", fill = TRUE)
print(slice_min(movies, n = 5, timestamp))

cat("6) summarize()", fill=TRUE)
cat("e.g. summarize by finding the mean of all ratings in the data set", fill = TRUE)
print(summarize(movies, mean(rating)))

cat("7) distinct()", fill=TRUE)
cat("e.g. form a data frame consisting of the unique User ID's", fill = TRUE)
print(distinct(movies, userId))

cat("8) mutate()", fill=TRUE)
cat("e.g. mutate the timestamp to a human readable date and time", fill = TRUE)
cat("in the new variable called when", fill = TRUE)
print(mutate(movies, when = lubridate::as_datetime(timestamp)))
## this uses a function from the lubridate package (part of the tidyverse) 
## without loading the package

cat("Verbs can be combined using the pipe operator %>%:", fill = TRUE)

cat("e.g. find the mean rating of Toy Story (1995)", fill = TRUE)
cat("with filter() then summarize()", fill = TRUE)
movies %>%
  filter(title == "Toy Story (1995)") %>%
  summarize(mean_rating = mean(rating)) %>%
  print() # using the pipe operator also for printing!

cat("e.g. find the titles of all movies that some user rated 5", fill = TRUE)
cat("with filter() then select() and distinct()", fill = TRUE)
movies %>% filter(rating == 5) %>% select(title) %>% distinct() -> topmovies
topmovies %>% print(n = 5)
cat("Same result without pipe operator?",
    all.equal(topmovies, distinct(select(filter(movies, rating == 5), title))),
    fill = TRUE)
cat("Same result with native R pipe operator?",
    all.equal(topmovies, movies |> filter(rating == 5) |>
                select(title) |> distinct()), fill = TRUE)

cat("Data can be grouped using the command group_by...", fill = TRUE)
movies %>%
  group_by(title) %>%
  print()
cat("...then they can be summarized by group:", fill = TRUE)

cat("e.g. find the mean rating by movie", fill = TRUE)
movies %>%
  group_by(title) %>%
  summarize(mean_rating = mean(rating)) %>%
  print()

cat("e.g. find the three most rated movies and their mean ratings",
    fill = TRUE)
movies %>%
  group_by(title) %>%
  summarize(number_of_ratings = n(), mean_rating = mean(rating)) %>%
  slice_max(number_of_ratings, n = 3) %>%
  print()

cat("We can use dplyr to...", fill = TRUE)

cat("...find all movies that have a mean rating of 5:", fill = TRUE)
movies %>%
  group_by(title) %>%
  summarize(number_of_observations = n(), mean_rating = mean(rating)) %>%
  filter(mean_rating == 5) %>%
  arrange(desc(number_of_observations)) %>% 
  print()

cat("...rank the worst movies that received at least 100 ratings:", fill = TRUE)
movies %>%
  group_by(title) %>%
  summarize(number_of_observations = n(), mean_rating = mean(rating)) %>%
  filter(number_of_observations >= 100) %>%
  arrange(mean_rating) %>%
  print()

cat("...find the user who made the most ratings:", fill = TRUE)
movies %>% 
  group_by(userId) %>%
  summarize(number_of_reviews = n(), mean_rating = mean(rating)) %>%
  slice_max(number_of_reviews, n = 1) %>%
  print()

cat("...find the best rated genre:", fill = TRUE)
movies %>% 
  group_by(genres) %>%
  summarize(number_of_reviews = n(), mean_rating = mean(rating)) %>%
  arrange(desc(number_of_reviews)) %>%
  filter(number_of_reviews >= 1000) %>%
  slice_max(mean_rating, n = 1) %>%
  print()

cat("...find the \"worst opinions\":", fill = TRUE)

movies %>%
  group_by(title) %>%
  mutate(num5 = sum(rating == 5), numRating = n()) %>%
  ungroup() %>%
  filter(rating == 5, num5 == 1) %>%
  select(userId, title, numRating) %>%
  slice_max(numRating, n = 5) %>% 
  print()

cat("-----------------", fill = TRUE)
cat("Storm tracks data", fill = TRUE)
cat("-----------------", fill = TRUE)

cat("The four storms that attained the highest overall wind speed are",
    fill = TRUE)
dplyr::storms %>%
  group_by(name, year) %>%
  summarize(max_wind = max(wind)) %>%
  ungroup() %>%
  slice_max(max_wind, n = 4) %>%
  print()