import java.util.*;

public class aostar {
public static Map<String, Integer>
	Cost(Map<String, Integer> H,
		Map<String, List<String> > condition, int weight)
{
	Map<String, Integer> cost = new HashMap<>();
	if (condition.containsKey("AND")) {
	List<String> AND_nodes = condition.get("AND");
	String Path_A = String.join(" AND ", AND_nodes);
	int PathA
		= AND_nodes.stream()
		.mapToInt(
		node -> H.get(node) + weight)
		.sum();
	cost.put(Path_A, PathA);
	}
	if (condition.containsKey("OR")) {
	List<String> OR_nodes = condition.get("OR");
	String Path_B = String.join(" OR ", OR_nodes);
	int PathB
		= OR_nodes.stream()
		.mapToInt(
		node -> H.get(node) + weight)
		.min()
		.getAsInt();
	cost.put(Path_B, PathB);
	}
	return cost;
}

public static Map<String, Map<String, Integer> >
	UpdateCost(
	Map<String, Integer> H,
	Map<String, Map<String, List<String> > > Conditions,
	int weight)
{
	List<String> Main_nodes
	= new ArrayList<>(Conditions.keySet());
	Collections.reverse(Main_nodes);
	Map<String, Map<String, Integer> > least_cost
	= new HashMap<>();
	for (String key : Main_nodes) {
	Map<String, List<String> > condition
		= Conditions.get(key);
	System.out.printf("%s: %s >>> %s%n", key,
						condition,
						Cost(H, condition, weight));
	Map<String, Integer> c
		= Cost(H, condition, weight);
	H.put(key, Collections.min(c.values()));
	least_cost.put(key, Cost(H, condition, weight));
	}
	return least_cost;
}

public static String ShortestPath(
	String Start,
	Map<String, Map<String, Integer> > Updated_cost,
	Map<String, Integer> H)
{
	String Path = Start;
	if (Updated_cost.containsKey(Start)) {
	int Min_cost = Collections.min(
		Updated_cost.get(Start).values());
	List<String> key = new ArrayList<>(
		Updated_cost.get(Start).keySet());
	List<Integer> values = new ArrayList<>(
		Updated_cost.get(Start).values());
	int Index = values.indexOf(Min_cost);
	List<String> Next
		= Arrays.asList(key.get(Index).split(" "));
	if (Next.size() == 1) {
		Start = Next.get(0);
		Path += "<--"
		+ ShortestPath(Start, Updated_cost,
						H);
	}
	else {
		Path += "<--(" + key.get(Index) + ") ";
		Start = Next.get(0);
		Path += "["
		+ ShortestPath(Start, Updated_cost,
						H)
		+ " + ";
		Start = Next.get(Next.size() - 1);
		Path += ShortestPath(Start, Updated_cost, H)
		+ "]";
	}
	}
	return Path;
}

public static void main(String[] args)
{
	Map<String, Integer> H = new HashMap<>();
	H.put("A", -1);
	H.put("B", 5);
	H.put("C", 2);
	H.put("D", 4);
	H.put("E", 7);
	H.put("F", 9);
	H.put("G", 3);
	H.put("H", 0);
	H.put("I", 0);
	H.put("J", 0);

	Map<String, Map<String, List<String> > > Conditions
	= new HashMap<>();
	Map<String, List<String> > aConditions
	= new HashMap<>();
	aConditions.put("OR", Arrays.asList("B"));
	aConditions.put("AND", Arrays.asList("C", "D"));
	Conditions.put("A", aConditions);
	Map<String, List<String> > bConditions
	= new HashMap<>();
	bConditions.put("OR", Arrays.asList("E", "F"));
	Conditions.put("B", bConditions);

	Map<String, List<String> > cConditions
	= new HashMap<>();
	cConditions.put("OR", Arrays.asList("G"));
	cConditions.put("AND", Arrays.asList("H", "I"));
	Conditions.put("C", cConditions);

	Map<String, List<String> > dConditions
	= new HashMap<>();
	dConditions.put("OR", Arrays.asList("J"));
	Conditions.put("D", dConditions);

	// weight
	int weight = 1;

	// Updated cost
	System.out.println("Updated Cost :");
	Map<String, Map<String, Integer> > Updated_cost
	= UpdateCost(H, Conditions, weight);
	System.out.println("*".repeat(75));
	System.out.println("Shortest Path :");
	System.out.println(
	ShortestPath("A", Updated_cost, H));
}
}
