# from google.protobuf.json_format import MessageToJson
import test_pb2 as test  # This is the generated Python proto module
import test_subdir.subdir_test_pb2 as subdir_test
def main():
    # Create a Geometry message
    geometry = test.Geometry()
    geometry.name = "geo"
    angle = subdir_test.Angles()

    angle.name = "testing"
    angle.radians = 5.6
    print(angle)
    print(geometry)
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