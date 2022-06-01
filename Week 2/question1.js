const check_string = (string) => {
    const newMap = new Map();

    for (let index = 0; index < string.length; index++) {
        let val = newMap.check_for_key(string[index])
        if( val === 0) {
            newMap.add_to_map(string[index])
        } else {
            newMap.increase_count(string[index]);
        }
    }

    console.log(newMap.array);
    console.log(newMap.size);

    return (
        newMap.check_lowest_count() === 1 ? 
        "No non duplicate letter" :
        `The first non duplicate character is ${newMap.check_lowest_count()}`
    )

}

class Map {
    size = -1
    array = []

    check_for_key (key) {
        if (this.size == -1)
        {
            return(0)
        }

        for (let index = 0; index <= this.size; index++) {
            if(this.array[index].key === key)
            {
                return(1)
            }            
        }

        return (0);
    }

    get_position (key) {
        for (let index = 0; index <= this.size; index++) {
            if (this.array[index].key === key){
                return (index);
            }            
        }
    }

    add_to_map(key) {
        const obj = {
            key: key,
            count: 1
        }

        this.array.push(obj);
        this.size++;
        console.log(`Key ${key} added to map!`);
    }

    increase_count (key) {
        let i = this.get_position(key);
        this.array[i].count++;
    }

    check_lowest_count () {
        for (let index = 0; index <= this.size; index++) {
            if (this.array[index].count === 1)
            {
                return (this.array[index].key)
            }          
        }

        return (1)
    }
}

console.log(check_string("minimum"))