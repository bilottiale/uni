# Load required packages
library(dplyr)
library(tidyr)

# Filter for the 2015 World Cup matches
str(world_cup)
head(world_cup)

world_cup_2015 <- world_cup %>%
  filter(competition %in% c("2015 FIFA Men's World Cup", "2015 FIFA Women's World Cup"))

# Compute total goals scored by each team
team_goals <- world_cup_2015 %>%
  # Select relevant columns
  select(team_1, score_1, team_2, score_2) %>%
  # Pivot to gather teams and their respective scores into one column
  pivot_longer(
    cols = c(team_1, team_2),
    names_to = "team_role",
    values_to = "team"
  ) %>%
  pivot_longer(
    cols = c(score_1, score_2),
    names_to = "score_role",
    values_to = "goals"
  ) %>%
  # Ensure matching teams with their respective scores
  filter(
    (team_role == "team_1" & score_role == "score_1") |
      (team_role == "team_2" & score_role == "score_2")
  ) %>%
  # Summarize total goals scored by each team
  group_by(team) %>%
  summarize(total_goals = sum(goals, na.rm = TRUE)) %>%
  # Sort in descending order of total goals
  arrange(desc(total_goals))

# Display the result
print(team_goals, n = 24)

ggplot(team_goals, aes(x = reorder(team, total_goals), y = total_goals)) +
  geom_bar(stat = "identity", fill = "skyblue") +
  coord_flip() +  # Flip the coordinates to make it horizontal
  labs(
    title = "Total Goals Scored by Each Team in the 2014 and 2015 World Cup",
    x = "Team",
    y = "Total Goals"
  ) +
  theme_minimal()