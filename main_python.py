# from google.protobuf.json_format import MessageToJson
import test_pb2  # This is the generated Python proto module

def main():
    # Create a Geometry message
    geometry = test_pb2.Geometry()

    # Set some values
    # geometry.points.extend([1.0, 2.0, 3.0])
    #
    # # Print the message as JSON
    # json_str = MessageToJson(geometry)
    # print(f"Geometry message as JSON: {json_str}")
    #
    # # Access specific fields
    # print(f"Number of points: {len(geometry.points)}")
    # print(f"Points: {list(geometry.points)}")
    print("working")

if __name__ == "__main__":
    main()