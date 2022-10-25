using System;
using System.Linq;
using System.Reflection;
using System.Collections.Generic;
using pizzainterfaces;

namespace testreflection
{
    class MexicanaPizza : pizzainterfaces.IPizza
    {
        string IPizza.Description()
        {
            return "Spicy pizza";
        }
    }
    class MexicanaPizzaMaker : pizzainterfaces.IPizzaMaker
    {
        IPizza IPizzaMaker.CreatePizza()
        {
            return new MexicanaPizza();
        }
    }
    class RandomPizzaMaker : pizzainterfaces.IPizzaMaker
    {
        static Random rnd = new Random();

        IPizza IPizzaMaker.CreatePizza()
        {
        
            List<Type> types = new List<Type>();

            foreach (Assembly a in AppDomain.CurrentDomain.GetAssemblies()){
                foreach (Type t in a.GetTypes()){
                    if(!t.IsAbstract && typeof(IPizza).IsAssignableFrom(t) ){
                    //Console.WriteLine(t);
                    types.Add(t);
                    }
                }
            }
            //Console.WriteLine("loaded n= "+ types.Count);
            var randomIndx = rnd.Next(types.Count);
            var ctorInfo = types[randomIndx].GetConstructor(
            BindingFlags.Instance | BindingFlags.Public, null,
            CallingConventions.HasThis, new Type[0], null);
     
            return (IPizza) ctorInfo.Invoke(null);
        

            }

        }


    
    class MainClass
    {
        public static void Main(string[] args)
        {
            // You may change this to an absolute path if you are not running it from the same location as the README suggests.
            // You can also comment out loading the dll (for example for testing the code first), but make sure to load the dll when
            // handing in the final result.
            Assembly a = Assembly.LoadFrom("ThirdPartyPlugin.dll");
            IPizzaMaker pm = new RandomPizzaMaker();
            foreach (int i in Enumerable.Range(1, 20)) {
                IPizza pizza = pm.CreatePizza();
                Console.WriteLine("{0} - {1}", pizza, pizza.Description());
            }
        }
    }
}
