import json

def build_category_tree(categories):
    category_map = {}
    
    
    for category in categories:
        category_map[category["id"]] = {
            "id": category["id"],
            "name": category["name"],
            "next": []
        }
    
    root = None
    
   
    for category in categories:
        if "parent" in category:
            parent_id = category["parent"]
            if parent_id in category_map:
                category_map[parent_id]["next"].append(category_map[category["id"]])
        else:
            root = category_map[category["id"]]
    
    return root


t = int(input())  

results = []

for _ in range(t):
    n = int(input())  
    input_data = ""
    for _ in range(n):
        input_data += input().strip()
    
    categories = json.loads(input_data)
    category_tree = build_category_tree(categories)
    
    results.append(category_tree)


print(json.dumps(results, ensure_ascii=False, indent=4))
